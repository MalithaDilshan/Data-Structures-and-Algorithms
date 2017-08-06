
class Main {


    public static void main(String[]args) {
        int i = 0;
        int j = 0;

        int[][] arrayOfInt = new int[10000][10000];


        int[] arrayOfInt1 = { 3751, 524, 6758, 3559, 2171, 5865, 8927, 3960, 7227, 7653, 7944, 8116, 6491, 7810, 5081, 496, 4674, 9338, 1862, 6088, 62, 9952, 938, 9031, 2370, 6453, 6636, 7185, 4043, 1818, 4564, 128, 7536, 6205, 5735, 1514, 7879, 6738, 8189, 3643, 2853, 9455, 8868, 4196, 2013, 708, 3421, 7600, 7322, 6533, 6005, 8607, 2024, 7733, 5678, 1169, 7628, 6657, 3787, 8368, 2099, 3734, 6395, 5658, 8328, 1519, 1196, 2202, 6719, 5615, 4929, 1954, 7871, 4664, 2366, 39, 9917, 2998, 1744, 5897, 8531, 7420, 4281, 4638, 8031, 9848, 1705, 394, 8952, 9380, 393, 2268, 6731, 7260, 9313, 2360, 1795, 5480, 7050, 5357 };


        for (int k = 0; k < 100; k++) {
            int m = arrayOfInt1[k];
            arrayOfInt[k][m] = 1;
        }

        SparseMatrix localSparseMatrix = new SparseMatrix();
        localSparseMatrix.createEmptyMatrix(10000);

        int n;

        for (int m = 0; m < 100; m++) {
            int value=1;
            n = arrayOfInt1[m];
            localSparseMatrix.set(m,n,value);

            /*localSparseMatrix.get(200,n);
            System.out.println(localSparseMatrix.get(0,3751));*/
        }
        /*System.out.println(arrayOfInt[0][0]);
        System.out.println(arrayOfInt[9999][9999]);*/
        //System.out.println(localSparseMatrix.get(20,64));
        int m;
        for (m = 0; m < 10000; m++) {
            for (n = 0; n < 10000; n++) {
                int i1 = localSparseMatrix.get(m, n);
                if (arrayOfInt[m][n] == i1) {
                    i++;
                } else {
                    j++;
                }
            }
        }

        System.out.println("Correct entries: " + i);
        System.out.println("Incorrect entries: " + j);
    }
}
