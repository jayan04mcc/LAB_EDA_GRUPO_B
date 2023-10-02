#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
#include <cmath>
//ORDENAMIENTO BURBUJA
void bubbleSort(std::vector<long>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        bool swapped = false;  // Para optimización
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        // Si no hubo intercambios en la pasada interna, entonces el arreglo ya está ordenado
        if (!swapped) {
            break;
        }
    }
}
//HEAP SORT
int left(long i) {
    return 2 * i+1;
}
int right(long i) {
    return 2 * i + 2;
}
void max_heapify(std::vector<long>&A,long i,long n) {
    int  l = left(i);
    int r = right(i);
    int max=i;

    
    if (l<n && A[l]>A[i]) {
        max = l;
    }
    if (r <n && A[r] > A[max]) {
        max = r;
    }
    
    if (max != i) {
        std::swap(A[max], A[i]);
        max_heapify(A, max,n);
    }   

}
void max_heap(std::vector<long>&A,long n) {
    n = A.size();
    for (int i = A.size()/2-1; i >=0; i--) {
        max_heapify(A, i,n);
    }
    std::cout << "\nIMPRIMIR:\n";
    for (auto& it : A) {
        std::cout << it << " ";
    }
}
void Heapsort(std::vector<long>&A) {
    int heap_size = A.size();
    max_heap(A,heap_size);
    for (int i = heap_size -1; i >= 0; i = i--) {
        std::swap(A[0],A[i]);
        heap_size--;
        max_heapify(A,0,heap_size);
    }
    
}
//INSERTION SORTING
void insertion_sort(std::vector<long>& A) {
    for (int i = 1; i < A.size(); i++){
        int key = A[i];
        int j = i - 1;
        while (j>=0 && A[j] > key) {
            A[j+1] = A[j];
            A[j] = key;
            j--;
        }
        
    }
}
//MERGE SORT 
void merget(std::vector<long>&arr, long p, long q, long r) {
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p+1;
    int n2 = r - q;
    std::vector<int>L(n1);
    std::vector<int>R(n2);
    for (int i = 0; i < L.size(); i++) {//[0,1...]
        L[i] = arr[i + p];
    }
    for (int j = 0; j < R.size(); j++) {//[... 7,8]
        R[j] = arr[q + 1+j];
    }
    int i, j, k;
    i = 0;//recorredor de L
    j = 0;//recorredor de R
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //caso que en uno haya mas que en el otro 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
//SELECTION SORT
void selectionSort(std::vector<long>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        
        // Buscar el mínimo en el subarray arr[i..n-1]
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Intercambiar el mínimo encontrado con el primer elemento
        if (min_idx != i) {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}
//SHELL SORT 
void shellSort(std::vector<long>& arr) {
    int n = arr.size();

    // Comenzar con un espacio grande y luego reducirlo
    for (int gap = n/2; gap > 0; gap /= 2) {
        
        // Realizar un insertion sort para este tamaño de espacio.
        // Los primeros elementos arr[0..gap-1] ya están en orden
        // (aunque gap podría ser mayor que n/2)
        for (int i = gap; i < n; i++) {
            // Agregar arr[i] a los elementos ya ordenados y mantener
            // ordenando arr[0..i-1] con gap actual
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
//QUICK SORT
int partition(std::vector<long>& arr, long low, long high) {
    int pivot = arr[high];  // Elegimos el pivot
    int i = (low - 1);  // Índice del elemento menor

    for (int j = low; j <= high - 1; j++) {
        // Si el elemento actual es menor que o igual al pivot
        if (arr[j] < pivot) {
            i++;  // Incrementamos el índice del elemento menor
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(std::vector<long>& arr, long low, long high) {
    if (low < high) {
        // pivot es el índice de partición. arr[pivot] está ahora en el lugar correcto
        int pivot = partition(arr, low, high);

        // Ordena separadamente los elementos antes y después de la partición
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


void guardarResultadosEnArchivo(const std::vector<double>& resultados, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo);

    if (archivo.is_open()) {
        for (const double& resultado : resultados) {
            archivo << resultado << std::endl;
        }
        archivo.close();
        std::cout << "Resultados guardados en " << nombreArchivo << std::endl;
    }
    else {
        std::cerr << "No se pudo abrir el archivo " << nombreArchivo << std::endl;
    }
}

std::random_device rd;
std::mt19937 gen(rd());

int random(int low, int high)
    {
        std::uniform_int_distribution<> dist(low, high);
        return dist(gen);
    }


    int main() {
    srand(time(nullptr)); // Inicializar semilla para rand()

    std::vector<long> pruebas{10,100,500,1000,5000,10000,50000,100000};
    
    std::vector<long> vec;
    std::vector<double>tiempos;
    for (long n : pruebas) {
        for (int i = 0; i < n; i++) {
            vec.push_back(random(1,10000));
        }

        auto start = std::chrono::high_resolution_clock::now();

        //bubbleSort(vec);
        //Heapsort(vec);
        //merget(vec, 0, vec.size() / 2 - 1, vec.size() - 1);
        //selectionSort(vec);
        //shellSort(vec);
        //quickSort(vec, 0, vec.size() - 1);
        //insertion_sort(vec);
        // Punto de finalización
        auto stop = std::chrono::high_resolution_clock::now();

        // Calculando la duración
        std::chrono::duration<double> duration = stop - start;

        std::cout << "Tiempo tomado por la funcion con un vector de "<<n<<" datos :"<< duration.count() << " microsegundos" << std::endl;
        tiempos.push_back(duration.count());
        
        vec.clear();
    }
    guardarResultadosEnArchivo(tiempos,"InsertionSort_resul");

    return 0;
    
}