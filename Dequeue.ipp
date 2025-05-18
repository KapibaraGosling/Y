// Polygon methods 
template <typename T>
void Deque<T>::resize() {
    size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
    T* new_buffer = new T[new_capacity];

    if (current_size > 0) {
        if (head < tail) {
            std::copy(buffer + head, buffer + tail, new_buffer);
        }
        else {
            std::copy(buffer + head, buffer + capacity, new_buffer);
            std::copy(buffer, buffer + tail, new_buffer + (capacity - head));
        }
    }

    delete[] buffer;
    buffer = new_buffer;
    head = 0;
    tail = current_size;
    capacity = new_capacity;
}


// 1. Конструктор по умолчанию
template <typename T>
Deque<T>::Deque() : buffer(nullptr), capacity(0), head(0), tail(0), current_size(0) {}

// 2. Конструктор с начальной емкостью
template <typename T>
Deque<T>::Deque(size_t initial_capacity) :
    buffer(new T[initial_capacity]),
    capacity(initial_capacity),
    head(0), tail(0), current_size(0) {
}


// 3. Конструктор копирования
template <typename T>
Deque<T>::Deque(const Deque& other) :
    buffer(new T[other.capacity]),
    capacity(other.capacity),
    head(0), tail(other.current_size), current_size(other.current_size) {
    std::copy(other.buffer, other.buffer + other.capacity, buffer);
}

//exchange копирует новое значение в старое и возвращает старое значение. 
// 4. Конструктор перемещения
template <typename T>
Deque<T>::Deque(Deque&& other) noexcept :
    buffer(std::exchange(other.buffer, nullptr)),  
    capacity(std::exchange(other.capacity, 0)),    
    head(std::exchange(other.head, 0)),
    tail(std::exchange(other.tail, 0)),
    current_size(std::exchange(other.current_size, 0)) {
}

// Конструктор из списка инициализации
template <typename T>
Deque<T>::Deque(std::initializer_list<T> init) :
    buffer(new T[init.size()]),
    capacity(init.size()),
    head(0), tail(init.size()), current_size(init.size()) {
    std::copy(init.begin(), init.end(), buffer);
}
template <typename T>
Deque<T>::~Deque() {
    delete[] buffer;
}







template <typename T>
void Deque<T>::push_front(const T& value) {//Сдвигаем влево, потом пишем
    if (current_size == capacity) resize();
    head = (head == 0) ? capacity - 1 : head - 1;
    buffer[head] = value;
    current_size++;
}

template <typename T>
void Deque<T>::push_back(const T& value) {//записываем в текущий, потом сдвигаем
    if (current_size == capacity) resize();

    buffer[tail] = value;
    tail = (tail + 1) % capacity;
    current_size++;
}
// Такой порядок для корректного создания начального элемента
// напр первый элемент записался бы в позицию 1, а не 0, если сначала сдвигали tail, потом писали

template <typename T>
void Deque<T>::pop_front() {
    if (empty()) throw std::out_of_range("Deque is empty");

    head = (head + 1) % capacity;
    current_size--;
}

template <typename T>
void Deque<T>::pop_back() {
    if (empty()) throw std::out_of_range("Deque is empty");

    // Сдвигаем tail влево с учетом кольцевого буфера
    tail = (tail == 0) ? capacity - 1 : tail - 1;
    current_size--;
}

template <typename T>
const T& Deque<T>::front() const{
    if (empty()) throw std::out_of_range("Deque is empty");
    return buffer[head];
}
template <typename T>
const T& Deque<T>::back()const {
    if (empty()) throw std::out_of_range("Deque is empty");
    return buffer[(tail == 0) ? capacity - 1 : tail - 1];
}

template <typename T>
size_t Deque<T>::size() const {
    return current_size;
}

template <typename T>
bool Deque<T>::empty() const {
    return current_size == 0;
}


template <typename T>
Deque<T>& Deque<T>::operator=(const Deque& other) {
    Deque temp(other);  // Создаем временную копию
    swap(*this, temp);
    return *this;
}



template <typename T>
std::string Deque<T>::toString() const {
    std::ostringstream oss;
    oss << *this;
    return oss.str();
}
template <typename T>
void swap(Deque<T>& a, Deque<T>& b) noexcept {
    using std::swap;

    swap(a.buffer, b.buffer);
    swap(a.capacity, b.capacity);
    swap(a.head, b.head);
    swap(a.tail, b.tail);
    swap(a.current_size, b.current_size);
}

template <typename T>
const T& Deque<T>::operator[](size_t index) const {
    if (index >= current_size) throw std::out_of_range("Index out of range");
    return buffer[(head + index) % capacity];
}

