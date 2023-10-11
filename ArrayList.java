public class ArrayList {

    private int array[];
    private int size = 0;

    // Return the current number of elements.
    public int size() {
        return size;
    }

    // Return the currently available size.
    public int capacity() {
        return array.length - this.size();
    }

    // Construct a new ArrayList with some space.
    public ArrayList() {
        array = new int[8];
    }

    // Increase the capacity to hold at least newSize elements.
    // This method never decreases the size of the ArrayList!
    public void reserve(int newSize) {
        if (newSize > array.length) {
            int[] z = array;
            array = new int[(int) (newSize * 1.35)];
            for (int i = 0; i < z.length; ++i) {
                array[i] = z[i];
            }
        } else {
            System.out.println("can't decrease size");
        }
    }

    // Add an element to the back of the ArrayList.
    public void push_back(int element) {

        if (this.capacity() < 2) {
            this.reserve((int) ((array.length + 1) * 1.35));
        }
        array[size] = element;
        size++;
    }

    // Remove the last element from the ArrayList.
    public void pop_back() {
        array[size] = 0;
        size--;
    }

    // Return the value at the given position.
    // constant time
    public int get_at(int index) {
        if (index >= size) {
            System.out.println("out of bounds");
            return -1;
        } else {
            return array[index];
        }
    }

    // Set the value at the given position.

    public void set_at(int index, int element) {
        System.out.println("they used set at +" + index + "" + this.size);
        array[index] = element;
    }

    // Insert the element at the given index. // The elements after that
    // positionare shifted towards the back. // linear
    public void insert(int index, int element) {
        if (this.capacity() < 2) {
            this.reserve((int) ((array.length + 1) * 1.35));
        }
        int z = array[index + 1];
        int x = array[index];
        for (int i = index; i < size; i++) {
            array[i + 1] = x;
            x = z;
            z = array[i + 2];
        }
        array[index] = element;
        size++;

    }

    // Erase array block of elements of size length, starting at index.

    public void erase(int index, int length) {
        int x = index;
        int il = index + length;

        System.out.println(array[5]);
        for (int i = il; i < size; ++i) {
            // System.out.println("this is a[" + x + "]: " + array[x]);
            array[x] = array[i];
            array[i] = 0;
            x++;
        }
        size = size - length;
    }

    public static void main(String[] args) {
        ArrayList a1 = new ArrayList();

        /*
         * a1.push_back(1); System.out.println("1 added to Array!"); a1.push_back(2);
         * System.out.println("2 added to Array!");
         * System.out.println("Element at index 0 : " + a1.get_at(0));
         * System.out.println("Element at index 1 : " + a1.get_at(1));
         *
         * System.out.println("Size of Array : " + a1.size());
         * System.out.println("Array capacity : " + a1.capacity());
         *
         * a1.set_at(2, 10); System.out.println("Element at index 2 : " + a1.get_at(2));
         * a1.insert(3, 5); System.out.println("Element at index 3 : " + a1.get_at(3));
         *
         * a1.pop_back(); System.out.println("Last Element Popped!");
         * System.out.println("Element at index 2 : " + a1.get_at(2));
         * System.out.println("Element at index 3 : " + a1.get_at(3));
         *
         * a1.insert(2, 9); System.out.println("New Element at index 2 : " +
         * a1.get_at(2)); System.out.println("New Element at index 3 : " +
         * a1.get_at(3));
         *
         * System.out.print("Reserve(2) : "); a1.reserve(2);
         *
         * a1.reserve(11); System.out.print("Reserve(11) : ");
         * System.out.println("New Capacity " + a1.capacity());
         *
         * a1.set_at(1, 2); System.out.println("Element at index 1 : " + a1.get_at(1));
         * System.out.println("Size of Array : " + a1.size());
         * System.out.println("Array Capacity : " + a1.capacity());
         *
         * ArrayList a2 = new ArrayList(); for (int i = 1; i < 11; i++) {
         * a2.push_back(i); }
         *
         * a2.erase(4, 2);
         *
         * System.out.println("Array : "); for (int i = 0; i < a2.size(); i++) {
         * System.out.println(a2.get_at(i)); }
         *
         * System.out.println("Size of Array A2 : " + a2.size());
         * System.out.println("Array A2 Capacity : " + a2.capacity());
         */
    }
}