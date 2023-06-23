#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tarea {
    int inicio, fin;
};

bool comparar(tarea a, tarea b) { // función auxiliar para ordenar las tareas según su tiempo de finalización
    return a.fin < b.fin;
}

void seleccion_tareas(vector<tarea> &tareas) {
    sort(tareas.begin(), tareas.end(), comparar); // se ordenan las tareas según su tiempo de finalización
    vector<tarea> seleccionadas;
    seleccionadas.push_back(tareas[0]); // se agrega la primera tarea a la lista de tareas seleccionadas
    int n = tareas.size();
    int j = 0; // índice de la última tarea seleccionada
    
    for (int i = 1; i < n; i++) {
        if (tareas[i].inicio >= tareas[j].fin) { // si la tarea actual no se empalma con la última tarea seleccionada
            seleccionadas.push_back(tareas[i]); // se agrega la tarea actual a la lista de tareas seleccionadas
            j = i;
        }
    }
    
    cout << "Tareas seleccionadas:\n";
    for (auto tarea : seleccionadas) {
        cout << "(" << tarea.inicio << ", " << tarea.fin << ")\n";
    }
}

int main() {
    vector<tarea> tareas = {{1, 3}, {2, 5}, {4, 7}, {6, 9}, {8, 10}};
    seleccion_tareas(tareas);
    return 0;
}
