import tkinter as tk
from tkinter import filedialog, messagebox, Checkbutton
import subprocess
import os
import logging
from io import StringIO
import sys


class InterpreterGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Perfacard Redactor")

        # Встроенный текстовый редактор
        self.text = tk.Text(root, wrap='none', height=20, width=80)
        self.text.pack(padx=10, pady=10)
        self.root.minsize(620, 600)
        self.root.maxsize(620, 600)

        # Кнопки
        frame = tk.Frame(root)
        frame.pack(pady=5)

        self.run_button = tk.Button(frame, text="Run", command=self.run_script)
        self.run_button.pack(side=tk.LEFT, padx=5)

        self.load_button = tk.Button(
            frame, text="Load Script", command=self.load_script)
        self.load_button.pack(side=tk.LEFT, padx=5)

        self.save_button = tk.Button(
            frame, text="Save Script", command=self.save_script)
        self.save_button.pack(side=tk.LEFT, padx=5)

        # Чек-бокс
        self.logging_enabled = tk.BooleanVar()  # Переменная для хранения состояния чекбокса
        self.test_button = tk.Checkbutton(
            frame, text='Logging every iteration',
            variable=self.logging_enabled,
            command=self.toggle_logging
        )
        self.test_button.pack(side=tk.LEFT, padx=130)

        # Вывод результата
        self.output = tk.Text(root, wrap='none', height=10,
                              width=80, bg="black", fg="white")
        self.output.pack(padx=10, pady=10)

    def toggle_logging(self):
        """Включает/выключает логирование в зависимости от состояния чекбокса"""
        if self.logging_enabled.get():
            logging.basicConfig(
                level=logging.DEBUG,
                format="%(asctime)s - %(levelname)s - %(message)s",
                filename='log.log',
                filemode='w',
            )
            logging.info("Logging started")
        else:
            logging.shutdown()  # Отключаем логирование
            open('log.log', 'w').close()  # Очищаем файл лога

    def load_script(self):
        path = filedialog.askopenfilename(
            initialdir="tray", filetypes=[("Text files", "*.txt")])
        if path:
            with open(path, 'r') as f:
                self.text.delete(1.0, tk.END)
                self.text.insert(tk.END, f.read())

    def save_script(self):
        path = filedialog.asksaveasfilename(initialdir="tray", defaultextension=".txt",
                                          filetypes=[("Text files", "*.txt")])
        if path:
            with open(path, 'w') as f:
                f.write(self.text.get(1.0, tk.END))

    def run_script(self):
        script = self.text.get(1.0, tk.END).strip()
        if not script:
            return

        self.output.delete(1.0, tk.END)
        
        # Логирование начала выполнения
        if self.logging_enabled.get():
            logging.info("Script execution started")

        # Если есть интерпретатор — используем его
        if os.path.exists("./interpreter.exe"):
            temp_path = "temp_script.txt"
            try:
                with open(temp_path, "w") as f:
                    f.write(script)
                
                result = subprocess.run(
                    ["./interpreter.exe", temp_path],
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True,
                    encoding='utf-8',
                    errors='replace'
                )
                
                if result.stdout:
                    self.output.insert(tk.END, result.stdout + "\n")
                    if self.logging_enabled.get():
                        logging.info(f"Output: {result.stdout}")
                if result.stderr:
                    self.output.insert(tk.END, "ERROR:\n" + result.stderr + "\n")
                    if self.logging_enabled.get():
                        logging.error(f"Error: {result.stderr}")
            
            except Exception as e:
                error_msg = f"Interpreter error: {str(e)}"
                self.output.insert(tk.END, error_msg + "\n")
                if self.logging_enabled.get():
                    logging.error(error_msg)
            
            finally:
                if os.path.exists(temp_path):
                    os.remove(temp_path)
        
        # Если интерпретатора нет — выполняем как Python-код
        # else:
        #     try:
        #         old_stdout = sys.stdout
        #         sys.stdout = output_catcher = StringIO()
                
        #         exec(script, globals(), locals())
                
        #         sys.stdout = old_stdout
        #         output = output_catcher.getvalue()
                
        #         if output:
        #             self.output.insert(tk.END, output + "\n")
        #             if self.logging_enabled.get():
        #                 logging.info(f"Python output: {output}")
            
        #     except Exception as e:
        #         error_msg = f"Python error: {str(e)}"
        #         self.output.insert(tk.END, error_msg + "\n")
        #         if self.logging_enabled.get():
        #             logging.error(error_msg)

        # Логирование завершения выполнения
        if self.logging_enabled.get():
            logging.info("Script execution finished")


if __name__ == "__main__":
    root = tk.Tk()
    app = InterpreterGUI(root)
    root.mainloop()