import cv2
import numpy as np
import face_recognition
import os
from datetime import datetime
import tkinter as tk
from tkinter import messagebox

os.makedirs('known_faces', exist_ok=True)
if not os.path.exists('attendance.csv'):
    with open('attendance.csv', 'w') as f:
        f.write('Name,Date,Time,Team Member\n')

TEAM_MEMBERS = ["Rawan Sotohy", "Jannah Ayman", "Sama Essam"]

class FaceRecognitionApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Face Recognition System")
        self.root.geometry("500x350")
        self.root.configure(bg='#f4dbbd')

        self.bg_color = '#f4dbbd'
        self.text_color = '#8c6238'
        self.button_bg = '#f4dbbd'
        self.button_border = 3

        self.main_frame = tk.Frame(root, bg=self.bg_color)
        self.main_frame.pack(expand=True, fill='both')

        self.content_frame = tk.Frame(self.main_frame, bg=self.bg_color)
        self.content_frame.place(relx=0.5, rely=0.5, anchor='center')  # Center it

        self.label = tk.Label(self.content_frame, text="Welcome to our attendance system",
                              font=("Arial", 16, "bold"), bg=self.bg_color, fg=self.text_color)
        self.label.pack(pady=(0, 20))  # Small padding below

        self.button_frame = tk.Frame(self.content_frame, bg=self.bg_color)
        self.button_frame.pack()

        self.login_btn = tk.Button(self.button_frame, text="Log In", command=self.open_login,
                                   width=16, height=1, bg=self.button_bg, fg=self.text_color,
                                   highlightbackground=self.text_color, highlightthickness=self.button_border,
                                   font=("Arial", 12, "bold"))
        self.login_btn.pack(pady=10, ipadx=5, ipady=3)

        self.signup_btn = tk.Button(self.button_frame, text="Sign Up", command=self.open_signup,
                                    width=16, height=1, bg=self.button_bg, fg=self.text_color,
                                    highlightbackground=self.text_color, highlightthickness=self.button_border,
                                    font=("Arial", 12, "bold"))
        self.signup_btn.pack(pady=10, ipadx=5, ipady=3)

        self.known_face_encodings = []
        self.known_face_names = []
        self.load_known_faces()
        self.attendance_recorded = False
    
    def load_known_faces(self):
        path = 'known_faces'
        images = []
        self.known_face_names = []
        
        try:
            myList = os.listdir(path)
            for cl in myList:
                if cl.lower().endswith(('.png', '.jpg', '.jpeg')):
                    curImg = cv2.imread(f'{path}/{cl}')
                    if curImg is not None:
                        images.append(curImg)
                        self.known_face_names.append(os.path.splitext(cl)[0])
            
            if images:
                self.known_face_encodings = self.find_encodings(images)
                print('Encoding Complete')
            else:
                print("No valid face images found in 'known_faces' directory")
                
        except Exception as e:
            print(f"Error loading images: {e}")
    
    def find_encodings(self, images):
        encode_list = []
        for img in images:
            img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
            encodings = face_recognition.face_encodings(img)
            if len(encodings) > 0:
                encode_list.append(encodings[0])
        return encode_list
    
    def mark_attendance(self, name):
        with open('attendance.csv', 'a') as f:
            now = datetime.now()
            date_str = now.strftime('%Y-%m-%d')
            time_str = now.strftime('%H:%M:%S')
            is_team_member = "Yes" if name in TEAM_MEMBERS else "No"
            f.write(f'{name},{date_str},{time_str},{is_team_member}\n')
        self.attendance_recorded = True
    
    def open_login(self):
        self.hide_main_window()
        self.login_window = tk.Toplevel(self.root)
        self.login_window.title("Log In")
        self.login_window.geometry("500x300")
        self.login_window.configure(bg=self.bg_color)

        content_frame = tk.Frame(self.login_window, bg=self.bg_color)
        content_frame.place(relx=0.5, rely=0.5, anchor='center')

        tk.Label(content_frame, text="Enter Username:",
                font=("Arial", 14, "bold"), bg=self.bg_color, fg=self.text_color).pack(pady=(0, 20))

        self.username_entry = tk.Entry(content_frame, font=("Arial", 12),
                                    highlightcolor=self.text_color, highlightthickness=1)
        self.username_entry.pack(ipady=5, pady=(0, 20))

        login_btn = tk.Button(content_frame, text="Enter", command=self.verify_login,
                            width=15, height=1, bg=self.button_bg, fg=self.text_color,
                            highlightbackground=self.text_color, highlightthickness=self.button_border,
                            font=("Arial", 12, "bold"))
        login_btn.pack(ipady=5, pady=(0, 10))

        self.login_window.protocol("WM_DELETE_WINDOW", self.show_main_window)

    
    def verify_login(self):
        username = self.username_entry.get().strip()
        if not username:
            messagebox.showerror("Error", "Please enter a username")
            return
        
        if username not in self.known_face_names and not os.path.exists(f'known_faces/{username}.jpg'):
            messagebox.showerror("Error", "Username doesn't exist, please sign up or enter a proper username")
            return
        
        self.login_window.destroy()
        self.attendance_recorded = False
        self.run_face_recognition(username)
    
    def open_signup(self):
        self.hide_main_window()
        self.signup_window = tk.Toplevel(self.root)
        self.signup_window.title("Sign Up")
        self.signup_window.geometry("500x300")
        self.signup_window.configure(bg=self.bg_color)

        content_frame = tk.Frame(self.signup_window, bg=self.bg_color)
        content_frame.place(relx=0.5, rely=0.5, anchor='center')

        tk.Label(content_frame, text="Enter New Username:",
                font=("Arial", 14, "bold"), bg=self.bg_color, fg=self.text_color).pack(pady=(0, 20))

        self.new_username_entry = tk.Entry(content_frame, font=("Arial", 12),
                                        highlightcolor=self.text_color, highlightthickness=1)
        self.new_username_entry.pack(ipady=5, pady=(0, 20))

        continue_btn = tk.Button(content_frame, text="Continue", command=self.verify_signup,
                                width=15, height=1, bg=self.button_bg, fg=self.text_color,
                                highlightbackground=self.text_color, highlightthickness=self.button_border,
                                font=("Arial", 12, "bold"))
        continue_btn.pack(ipady=5, pady=(0, 10))

        self.signup_window.protocol("WM_DELETE_WINDOW", self.show_main_window)

    
    def verify_signup(self):
        username = self.new_username_entry.get().strip()
        if not username:
            messagebox.showerror("Error", "Please enter a username")
            return
        
        if (username in self.known_face_names or 
            os.path.exists(f'known_faces/{username}.jpg') or 
            os.path.exists(f'known_faces/{username}.png') or 
            os.path.exists(f'known_faces/{username}.jpeg')):
            messagebox.showerror("Error", "Username already exists, please log in or enter a new username")
            return
        
        self.signup_window.destroy()
        self.capture_new_face(username)
    
    def capture_new_face(self, username):
        cap = cv2.VideoCapture(0)
        cv2.namedWindow('Register Face', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Register Face', 800, 600)
        
        last_good_frame = None
        quality_warning_shown = False
        
        while True:
            ret, frame = cap.read()
            if not ret:
                messagebox.showerror("Error", "Failed to access camera")
                break

            cv2.putText(frame, "Press 'S' to save face", (50, 50), 
                    cv2.FONT_HERSHEY_SIMPLEX, 1.5, (0, 255, 0), 3)
            cv2.putText(frame, "Press 'Q' to cancel", (50, 100), 
                    cv2.FONT_HERSHEY_SIMPLEX, 1.5, (0, 0, 255), 3)
            
            face_locations = face_recognition.face_locations(frame)
            
            if face_locations:
                (top, right, bottom, left) = face_locations[0]

                face_height = bottom - top
                face_width = right - left
                min_face_size = min(frame.shape[0], frame.shape[1]) * 0.2 
                
                if (face_height >= min_face_size and face_width >= min_face_size and
                    top > 50 and bottom < frame.shape[0] - 50 and
                    left > 50 and right < frame.shape[1] - 50):

                    cv2.rectangle(frame, (left, top), (right, bottom), (0, 255, 0), 3)
                    last_good_frame = frame
                    quality_warning_shown = False
                else:
                    cv2.rectangle(frame, (left, top), (right, bottom), (0, 255, 255), 3)
                    if not quality_warning_shown:
                        cv2.putText(frame, "Move closer/center your face", (50, 150), 
                                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 255), 2)
            else:
                if not quality_warning_shown:
                    cv2.putText(frame, "No face detected", (50, 150), 
                            cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255), 2)
            
            cv2.imshow('Register Face', frame)
            
            key = cv2.waitKey(1)
            if key & 0xFF == ord('s'):
                if last_good_frame is not None and face_locations:
                    (top, right, bottom, left) = face_locations[0]
                    face_image = last_good_frame[top:bottom, left:right]
                    
                    rgb_face = cv2.cvtColor(face_image, cv2.COLOR_BGR2RGB)
                    encodings = face_recognition.face_encodings(rgb_face)
                    
                    if len(encodings) > 0:
                        cv2.imwrite(f'known_faces/{username}.jpg', face_image)
                        self.load_known_faces()

                        saved_img = cv2.imread(f'known_faces/{username}.jpg')
                        if saved_img is not None:
                            saved_encoding = face_recognition.face_encodings(cv2.cvtColor(saved_img, cv2.COLOR_BGR2RGB))
                            if len(saved_encoding) > 0:
                                messagebox.showinfo("Success", "Face registered successfully!")
                                cap.release()
                                cv2.destroyAllWindows()
                                break
                            else:
                                os.remove(f'known_faces/{username}.jpg')
                                messagebox.showerror("Error", "Couldn't process saved image. Please try again.")
                        else:
                            messagebox.showerror("Error", "Failed to save image properly. Please try again.")
                    else:
                        messagebox.showerror("Error", "Couldn't extract face features. Please try again.")
                else:
                    messagebox.showerror("Error", "No good quality face detected. Please ensure:")
                    messagebox.showerror("Error", "- Your face is clearly visible\n- You're close enough to the camera\n- The lighting is good")
            
            elif key & 0xFF == ord('q'):
                break
            
            if cv2.getWindowProperty('Register Face', cv2.WND_PROP_VISIBLE) < 1:
                break

        cap.release()
        cv2.destroyAllWindows()
        self.show_main_window()
    
    def run_face_recognition(self, username):
        cap = cv2.VideoCapture(0)
        cv2.namedWindow('Face Recognition', cv2.WINDOW_NORMAL)
        cv2.resizeWindow('Face Recognition', 800, 600)
        
        user_image = cv2.imread(f'known_faces/{username}.jpg')
        if user_image is None:
            messagebox.showerror("Error", f"Could not load face image for {username}")
            self.show_main_window()
            return
            
        user_face_encoding = face_recognition.face_encodings(cv2.cvtColor(user_image, cv2.COLOR_BGR2RGB))
        if not user_face_encoding:
            messagebox.showerror("Error", f"Could not detect face in image for {username}")
            self.show_main_window()
            return
            
        user_face_encoding = user_face_encoding[0]
        recognized = False
        
        while True:
            ret, frame = cap.read()
            if not ret:
                messagebox.showerror("Error", "Failed to access camera")
                break
            
            small_frame = cv2.resize(frame, (0, 0), fx=0.25, fy=0.25)
            rgb_small_frame = cv2.cvtColor(small_frame, cv2.COLOR_BGR2RGB)
            
            face_locations = face_recognition.face_locations(rgb_small_frame)
            face_encodings = face_recognition.face_encodings(rgb_small_frame, face_locations)
            
            for (top, right, bottom, left), face_encoding in zip(face_locations, face_encodings):
                top *= 4
                right *= 4
                bottom *= 4
                left *= 4
                
                matches = face_recognition.compare_faces([user_face_encoding], face_encoding)
                face_distances = face_recognition.face_distance([user_face_encoding], face_encoding)
                
                if matches[0] and face_distances[0] < 0.6:
                    if not self.attendance_recorded:
                        self.mark_attendance(username)
                        recognized = True
                        break
                    color = (0, 255, 0)
                else:
                    name = "UNKNOWN"
                    color = (0, 0, 255)
                
                cv2.rectangle(frame, (left, top), (right, bottom), color, 3)  # Thicker border
                cv2.rectangle(frame, (left, bottom - 50), (right, bottom), color, cv2.FILLED)
                cv2.putText(frame, name, (left + 10, bottom - 15), 
                            cv2.FONT_HERSHEY_DUPLEX, 1.5, (255, 255, 255), 2)  # Larger text
            
            if recognized:
                break
            
            cv2.imshow('Face Recognition', frame)
            
            if cv2.waitKey(1) & 0xFF == ord('q'):
                break
            
            if cv2.getWindowProperty('Face Recognition', cv2.WND_PROP_VISIBLE) < 1:
                break
        
        cap.release()
        cv2.destroyAllWindows()
        
        if recognized:
            messagebox.showinfo("Welcome", f"Hello, {username}")
        
        self.show_main_window()
    
    def hide_main_window(self):
        self.root.withdraw()
    
    def show_main_window(self):
        self.root.deiconify()
        if hasattr(self, 'login_window'):
            self.login_window.destroy()
        if hasattr(self, 'signup_window'):
            self.signup_window.destroy()

if __name__ == "__main__":
    root = tk.Tk()
    app = FaceRecognitionApp(root)
    root.mainloop()