#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Patient {
  string name;
  int priority;
  int start_time;
  int end_time;
  bool life_threatening;

  bool operator<(const Patient& other) const {
    if (life_threatening && !other.life_threatening) {
      return true;
    } else if (!life_threatening && other.life_threatening) {
      return false;
    } else {
      return priority < other.priority;
    }
  }
};

int main() {
  // Initialize the priority queue with the given data
  priority_queue<Patient> pq;
  pq.push({"Bob Bleeding", 6, 0, 0, false});
  pq.push({"Frank Feelingbad", 3, 0, 0, false});
  pq.push({"Cathy Coughing", 5, 0, 0, false});
  pq.push({"Sam Sneezing", 0, 0, 0, true});
  pq.push({"Paula Pain", 4, 0, 0, false});
  pq.push({"Sid Sickly", 0, 0, 0, true});
  pq.push({"Alice Ailment", 7, 0, 0, false});
  pq.push({"Irene Ill", 1, 0, 0, false});
  pq.push({"Tom Temperature", 8, 0, 0, false});

  // Doctor starts working at noon
  int current_time = 12 * 60; // in minutes

  while (!pq.empty()) {
    // Get the next patient from the priority queue
    Patient patient = pq.top();
    pq.pop();

    // Determine the start and end times for the patient's appointment
    int start_time = current_time;
    int end_time = current_time + 25;
    current_time = end_time;

    // Handle interruptions due to life-threatening scenarios
    if (patient.life_threatening) {
      cout << patient.name << " has a life-threatening issue and must be treated immediately at " << start_time / 60 << ":" << start_time % 60 << endl;
      patient.start_time = start_time;
      patient.end_time = end_time;
      continue;
    }

    // Handle interruptions due to the next patient's life-threatening scenario
    while (!pq.empty() && pq.top().life_threatening && pq.top().priority > patient.priority + 1) {
      Patient next_patient = pq.top();
      pq.pop();
      cout << next_patient.name << " has a life-threatening issue and must be treated immediately at " << start_time / 60 << ":" << start_time % 60 << endl;
      next_patient.start_time = start_time;
      next_patient.end_time = end_time;
      pq.push(patient);
      patient = next_patient;
    }

    // Treat the patient and record the start and end times
    patient.start_time = start_time;
    patient.end_time = end_time;
    cout << patient.name << " is being treated from " << start_time / 60 << ":" << start_time % 60 << " to " << end_time / 60 << ":" << end_time % 60 << endl;
  }

  return 0;
}