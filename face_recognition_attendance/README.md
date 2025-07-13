# Face Recognition Attendance System

A Python-based system for marking attendance using face recognition via webcam. Built with `opencv-python`, `face_recognition`, `numpy`, and `tkinter`.

---

## Features

- Register & login using face detection.
- Real-time webcam feedback.
- Attendance saved in `attendance.csv` (Name, Date, Time, Team Member).
- Team members flagged in the CSV.
- Simple GUI using `tkinter`.

---


## Project Structure

```
.
├── known_faces/
│   ├── username1.jpg
│   ├── username2.jpg
│   └── ...
├── attendance.csv
└── main.py
```

-main.py: The main application script containing the FaceRecognitionApp class and the Tkinter GUI logic.

-known_faces/: This directory is automatically created and stores the captured face images of registered users. Each image is named after the username (e.g., JohnDoe.jpg).

-attendance.csv: This file stores the attendance records, created automatically if it doesn't exist.


---

## Getting Started

Follow these steps to get the Face Recognition Attendance System up and running on your local machine.

### 1\. Clone the Repository
### 2\. Install dependencies
### 3\. Run the Application
Execute the main Python script:
```bash
python main.py
```
