import os
from tkinter import Tk, filedialog
import shutil

def get_next_image_number():
    image_files = [f for f in os.listdir("images") if os.path.isfile(os.path.join("images", f))]
    image_numbers = [int(f.split("-")[1].split(".")[0]) for f in image_files if f.startswith("img-")]
    next_number = max(image_numbers) + 1 if image_numbers else 1
    return next_number

def upload_image():
    root = Tk()
    root.withdraw()

    image_path = filedialog.askopenfilename(title="Select Image File", filetypes=(("Image Files", "*.png *.jpg *.jpeg *.gif *.bmp"), ("All Files", "*.*")))

    if image_path:
        image_filename = os.path.basename(image_path)
        image_number = get_next_image_number()
        target_filename = f"img-{image_number}{os.path.splitext(image_filename)[1]}"
        target_path = os.path.join("images", target_filename)

        try:
            shutil.move(image_path, target_path)
            print(f"Image uploaded successfully as {target_filename}!")
        except:
            print("An error occurred while uploading the image.")
    else:
        print("No file selected.")

def main():
    user_input = input("Enter 1 to upload an image, or 0 to exit: ")
    if user_input == "1":
        upload_image()
    elif user_input == "0":
        print("Not uploading an image.")
    else:
        print("Invalid input.")

if __name__ == "__main__":
    main()