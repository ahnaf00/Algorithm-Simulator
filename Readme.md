# ✨ CPU Scheduling Algorithms Simulator

## 📜 Overview
This project demonstrates the implementation of four fundamental CPU scheduling algorithms with dynamic input handling and Gantt chart visualizations. It provides a robust framework to calculate and analyze process metrics like waiting time and turnaround time, enabling easy comparison of algorithms based on performance.

## 🚀 Features
- **Implemented Algorithms:**
  - First Come First Serve (FCFS)
  - Shortest Job First (SJF) - Preemptive and Non-Preemptive
  - Priority Scheduling - Preemptive and Non-Preemptive
  - Round Robin (RR)
- **Dynamic Input Handling:** Accepts process details such as arrival time, burst time, priority, and time quantum.
- **Gantt Chart Visualization:** Displays execution order of processes for each algorithm.
- **Process Metrics Calculation:**
  - Waiting Time
  - Turnaround Time
- **Comparison Feature:** Evaluates and compares algorithms based on average metrics for the same set of processes.

---

## 📂 Project Structure
The project follows a modular and organized approach:
- **Header File:** `scheduling.h`
  - Contains struct definitions for process details.
  - Includes function prototypes for scheduling algorithms and utility functions.
- **Main File:** `main.cpp`
  - Provides a menu-driven interface for user interaction.
  - Calls specific scheduling functions based on user input.
- **Source File:** `scheduling.cpp`
  - Implements all scheduling algorithms and utility functions.

---

## 📜 Functions
### **FCFS Scheduling**
- Processes are scheduled in the order of their arrival times.
- Simplicity makes it easy to implement, but it can lead to the "convoy effect."

### **SJF Scheduling**
- Supports preemptive and non-preemptive variants.
- Prioritizes processes based on their burst times.
- Often results in optimal waiting times but may cause starvation for long processes.

### **Priority Scheduling**
- Handles both preemptive and non-preemptive cases.
- Schedules processes based on their user-defined priority levels.
- Flexible but can lead to starvation for low-priority processes.

### **Round Robin Scheduling**
- Uses a fixed time quantum for process execution.
- Implements fairness through a circular queue mechanism.
- Suitable for time-sharing systems but may increase turnaround times.

### **Comparison Function**
- Evaluates all algorithms for the same set of processes.
- Compares average waiting and turnaround times.
- Outputs a performance summary for analysis.

---

## 📥 Input and 📤 Output
### **Input**
1. Number of processes.
2. Process details:
   - Arrival Time
   - Burst Time
   - Priority (for Priority Scheduling)
   - Time Quantum (for Round Robin)

### **Output**
- Gantt chart for each scheduling algorithm.
- Metrics for individual processes:
  - Waiting Time
  - Turnaround Time
- Average metrics for algorithm comparison.

---

## 🖥️ How to Run
### **Requirements**
- A C++ compiler (e.g., GCC, Clang).
- Command-line interface.

### **Steps**
1.  Clone the repository:
   ```bash
   git clone https://github.com/your-username/cpu-scheduling.git

2.  Navigate to the project directory:
    ```bash
    cd cpu-scheduling

3.  Compile the code:
    ```bash
    g++ -o cpu_scheduling main.cpp scheduling.cpp

4.  Run the executable:
    ```bash
    ./cpu_scheduling

## 📊 Performance Analysis

### **Comparison Metrics**
- **FCFS:** 
  - Simple and straightforward but prone to the "convoy effect," where short processes are delayed behind longer ones.
- **SJF:** 
  - Optimized for minimizing waiting time but may lead to starvation for processes with longer burst times.
- **Priority Scheduling:** 
  - Flexible and prioritizes processes based on their priority levels, but low-priority processes may starve.
- **Round Robin:** 
  - Ensures fairness with time-sharing but can result in higher turnaround times due to frequent context switching.

### **Findings**
- **SJF** generally provides the best average waiting time due to its burst-time-based prioritization.
- **Round Robin** is well-suited for time-sharing systems where fairness is critical.
- **Priority Scheduling** is effective in systems where task importance varies, making it ideal for priority-based scenarios.

---

## 🔧 Future Enhancements
- Add support for **Multilevel Queue Scheduling** to handle diverse process categories.
- Implement **real-time process simulation** for dynamic scheduling analysis.
- Enhance the **user interface** to include better visualization of results and metrics.

---

## 📜 License
This project is licensed under the [MIT License](LICENSE).

---

## 👨‍💻 Author
**Ahnaf**  
Bachelor of Science in Computer Science and Engineering  
East West University  