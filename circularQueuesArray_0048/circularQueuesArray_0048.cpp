#include <iostream>
using namespace std;

class Queues {
    int FRONT, REAR, max = 5;
    int queues_array[5];

public:
    // Constructor untuk inisialisasi queue
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    // Method untuk menambahkan elemen ke dalam queue
    void insert() {
        int num;
        cout << "Enter a number : ";
        cin >> num;
        cout << endl;

        //Cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue Overflow\n";
            return;
        }
        //Cek apakah antrian kosong
        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            //Jika REAR berada di posisi terakhir array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queues_array[REAR] = num; // Menambahkan elemen ke antrian
    }

    // Method untuk menghapus elemen dari queue
    void remove() {
        // cek apakah antrian kosong // ini
        if (FRONT == -1) {
            cout << "Queues Underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is : " << queues_array[FRONT] << "\n";

        //Cek jika antrian hanya memiliki satu element
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            //Jika element yang dihapus berada di posisi terakhir array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }

    void display() {

        int FRONT_Position = FRONT;
        int REAR_Position = REAR;

        //Cek apakah antrian kosong
        if (FRONT_Position == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        //Jika FRONT <= REAR, iterasi dari FRONT hingga REAR
        if (FRONT_Position <= REAR_Position) {
            while (FRONT_Position <= REAR_Position) {
                cout << queues_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
            cout << endl;
        }
        else {
            //Jika FRONT > REAR, iterasi dari FRONT hingga akhir array
            while (FRONT_Position <= max - 1) {
                cout << queues_array[FRONT_Position] << " ";
                FRONT_Position++;
            }
            FRONT_Position = 0; //set front = 0

            //Iterasi dari awal array hingga REAR
            while (FRONT_Position <= REAR_Position) {
                cout << queues_array[FRONT] << " ";
                FRONT_Position++;
            }
        }
    }
};


int main()
{
    Queues q;
    char ch;

    while (true) {
        try {
            cout << "Menu" << endl;
            cout << "1. Implement insert operation" << endl;
            cout << "2. Implement delete operation" << endl;
            cout << "3. Display values" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice (1-4) : " << endl;
            cin >> ch;
            cout << endl;

            switch (ch) {
            case '1': {

                q.insert();
                break;
            }
            case '2': {
                q.remove();
                break;
            }
            case '3': {
                q.display();
                break;
            }

}

