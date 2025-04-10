#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

clock_t t;

double time_taken;
int passloop;
double timetime;

extern double m1[250][250];
extern double m2[250][250];
extern double c[250][250];

int when_record(int indicator) {
    if (indicator == 0) {
        int answer;
        printf("Would you like to record individual tests or the average?[0]Each/[1]Average/[2]None\n");
        printf(">>");
        scanf("%d", &answer);
        if (answer == 0 || answer == 1 || answer == 2) {
            return answer;
        } else {
            return 1;
        }
    } else {
        return indicator;
    }
}

void reset() {
    timetime = 0;
    passloop = 0;
}

void clear(int indicator) {
    FILE *f = NULL;

    if (indicator == 0) {
        for (int i = 1; i <= 10; i++) {
            char filename[20];
            snprintf(filename, sizeof(filename), "scores%d.txt", i);
            f = fopen(filename, "w");
            if (f) fclose(f);
        }
        return;
    }

    if (indicator >= 1 && indicator <= 10) {
        char filename[20];
        snprintf(filename, sizeof(filename), "scores%d.txt", indicator);
        f = fopen(filename, "w");
        if (f) fclose(f);
    }
}

double startc() {
    t = clock();
    return t;
}

double endc() {
    t = clock() - t;
    time_taken = ((double)t) / (double)CLOCKS_PER_SEC;
    timetime += (double)time_taken;
    return time_taken;
}

int run_times(int indicator) {
    if (indicator == 0) {
        int answer;
        printf("How many passes? (10 will take around 20-120 seconds depending on test)\n");
        printf(">>");
        scanf("%d", &answer);
        return answer;
    } else {
        return indicator;
    }
}

void write_scores(int test) {
    if (passloop == 0) return;
    FILE *f = NULL;
    switch (test) {
        //opens and appends based on the test number
        case 1:
            f = fopen("scores1.txt", "a");
            break;
        case 2:
            f = fopen("scores2.txt", "a");
            break;
        case 3:
            f = fopen("scores3.txt", "a");
            break;
        case 4:
            f = fopen("scores4.txt", "a");
            break;
        case 5:
            f = fopen("scores5.txt", "a");
            break;
        case 6:
            f = fopen("scores6.txt", "a");
            break;
        case 7:
            f = fopen("scores7.txt", "a");
            break;
        case 8:
            f = fopen("scores8.txt", "a");
            break;
        case 9:
            f = fopen("scores9.txt", "a");
            break;
        case 10:
            f = fopen("scores10.txt", "a");
            break;
        default:
            return;
    }
    if (f == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(f, "%.10f\n", timetime / passloop);
    fclose(f);
}

void write_all_scores(int test) {
    //this is for writing the time of each test, and not the average
    FILE *f = NULL;
    switch (test) {
        case 1:
            f = fopen("scores1.txt", "a");
            break;
        case 2:
            f = fopen("scores2.txt", "a");
            break;
        case 3:
            f = fopen("scores3.txt", "a");
            break;
        case 4:
            f = fopen("scores4.txt", "a");
            break;
        case 5:
            f = fopen("scores5.txt", "a");
            break;
        case 6:
            f = fopen("scores6.txt", "a");
            break;
        case 7:
            f = fopen("scores7.txt", "a");
            break;
        case 8:
            f = fopen("scores8.txt", "a");
            break;
        case 9:
            f = fopen("scores9.txt", "a");
            break;
        case 10:
            f = fopen("scores10.txt", "a");
            break;
        default:
            return;
    }
    if (f == NULL) {
        return;
    }
    fprintf(f, "%.10f\n", time_taken);
    fclose(f);
}

void mult_mat(int not, int runs, int record){
    reset();
    int x,y;
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);

        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = (m1[x][y] * m2[x][y]);
                }
            }
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = 0;
                }
            }
        }
        endc();
        if (record == 0){
            write_all_scores(1);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(1);
    }
}

void check_mat(int not, int runs, int record){
    reset();
    int x, y;
    
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    if (m1[x][y] == m2[x][y]) {
                        c[x][y] = 2;
                    } else {
                        c[x][y] = 1;
                    }
                }
            }
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = 0;
                }
            }
        }
        endc();
        if (record == 1){
            write_all_scores(2);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(2);
    }
}

void print_speed(int not, int runs, int record){
    reset();
    
    
    for (passloop = 0; passloop < runs; passloop++) {
        startc();
        int z;
        for (z = 0; z < not; z++) {
            printf("qwertyuiopasdfghjklzxcvbnm1234567890!@#$^&*()-=_+[]{};':\",./<>?\n");
        }
        endc();
        if (record == 0){
            write_all_scores(3);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(3);
    }
}

void string(long long int not, int runs, int record){
    reset();
    char string[2000000] = "c";
    char adding = 'c';
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        for (int z = 0; z < not && strlen(string) < sizeof(string) - 1; z++) {
            strncat(string, &adding, 1);
        }
        endc();
        string[0] = '\0';
        if (record == 0){
            write_all_scores(4);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(4);
    }
}

void pi(long long int not, int runs, int record){
    reset();
    long double p = 0;
    long double cir = 68.65838503937458;
    long double rad = 10.9273213637231;
    
    
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            p = cir/(rad*2);
        }
        endc();
        p = 0;
        if (record == 0){
            write_all_scores(5);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(5);
    }
}

float fib(float num) {
    if (num <= 1){
        return num;
    }
    return fib(num-1) + fib(num-2);
}

void fib1(int not, int runs, int record){
    reset();
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            fib(36);
        }
        endc();
        if (record == 0){
            write_all_scores(6);
        }
    }
    if (record == 1){
        write_scores(6);
    }
    printf("%.10f\n", timetime / passloop);
}

void division(int not, int runs, int record){
    reset();
    int x, y;
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = (m1[x][y] / m2[x][y]);
                }
            }
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    c[x][y] = 0;
                }
            }
        }
        endc();
        if (record == 0){
            write_all_scores(7);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(7);
    }
}

void doubles(int not, int runs, int record){
    reset();
    long int number1 = 1;
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            number1 = number1 * 2;
        }
        endc();
        if (record == 0){
            write_all_scores(8);
        }
    }
    printf("%.10f\n", timetime / passloop);
    if (record == 1){
        write_scores(8);
    }
}

void file_write(int not, int runs, int record){
    reset();
    FILE *test = fopen("test", "a");
    if (test == NULL) {
        return;
    }
    int x, y;
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0; z < not; z++) {
            for (x = 0; x < 250; x++) {
                for (y = 0; y < 250; y++) {
                    fprintf(test, "%.10f\n", m1[x][y]);
                }
            }
        }
        endc();
        if (record == 0){
            write_all_scores(9);
        }
        test = fopen("test", "w");
        fprintf(test, "");
    }
    printf("%.10f\n", timetime / passloop);
    fclose(test);
    if (record == 1){
        write_scores(9);
    }
}

int fib3(int not) {
    int n1 = 0, n2 = 1, n3, i;
    for (i = 0; i <= not; i++) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    return n2;
}

void fib4(int not, int runs, int record){
    reset();
    for (passloop = 0; passloop < runs; passloop++) {
        printf("Pass %d\n", passloop + 1);
        startc();
        int z;
        for (z = 0;z<not;z++) {
            fib3(40000);
        }
        endc();
        if (record == 0){
            write_all_scores(10);
        }
    }
    if (record == 1){
        write_scores(10);
    }
    printf("%.10f\n", timetime / passloop);
}

void queue(){
    int tests[50];
    int runs[50];
    int rec;
    int run = 0;
    while (1){
        printf("Enter the test number you would like to run or 0 to finish:");
        scanf("%d", &tests[run]);
        if (tests[run] <= 0 || tests[run] > 10){
            break;
        }
        runs[run] = run_times(0);
        run++;
    }
    rec = when_record(0);
    for (int i = 0; i < run; i++){
        if (tests[i] == 1){
            mult_mat(50000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 2){
            check_mat(50000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 3){
            print_speed(2000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 4){
            string(300000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 5){
            pi(1000000000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 6){
            fib1(150, run_times(runs[i]), rec);
        }
        else if (tests[i] == 7){
            division(70000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 8){
            doubles(900000000, run_times(runs[i]), rec);
        }
        else if (tests[i] == 9){
            file_write(100, run_times(runs[i]), rec);
        }
        else if (tests[i] == 10){
            fib4(100000, run_times(runs[i]), rec);
        }
    }
}

void enterToContinue() {
    printf("Press Enter to continue...");
    while (getchar() != '\n');
    getchar();
}

int main() {
    int ans;
    while (1) {
        printf("---------------------------------------------------------------\n");
        printf("                  Welcome to benchmark.\n\n");          
        printf("                [1]- Float Matrix Multiplication\n");
        printf("                [2]- Float Matrix Verification\n");
        printf("                [3]- Console Print Speed\n");
        printf("                [4]- String Concatenation\n");
        printf("                [5]- Pi\n");
        printf("                [6]- Fibonacci\n");
        printf("                [7]- Matrix Division\n");
        printf("                [8]- Doubling\n");
        printf("                [9]- File Writing\n");
        printf("                [10]- Fibonacci 2\n\n");
        printf("                [11]- Set up a queue of tests.\n");
        printf("                [12]- Clear logs.\n");
        printf("                [0]- Quit\n");
        printf("---------------------------------------------------------------\n");
        printf(">>");
        scanf("%d", &ans);
        switch(ans) {
            case 1:
                mult_mat(50000, run_times(0), when_record(0));
                break;
            case 2:
                check_mat(50000, run_times(0), when_record(0));
                break;
            case 3:
                print_speed(2000, run_times(0), when_record(0));
                break;
            case 4:
                string(300000, run_times(0), when_record(0));
                break;
            case 5:
                pi(1000000000, run_times(0), when_record(0));
                break;
            case 6:
                fib1(150, run_times(0), when_record(0));
                break;
            case 7:
                division(70000, run_times(0), when_record(0));
                break;
            case 8:
                doubles(900000000, run_times(0), when_record(0));
                break;
            case 9:
                file_write(100, run_times(0), when_record(0));
                break;
            case 10:
                fib4(100000, run_times(0), when_record(0));
                break;
            case 11:
                queue();
                break;
            case 12:
                printf("Enter the log number you would like to clear or 0 to clear all: ");
                int log;
                scanf("%d", &log);
                clear(log);
                break;
            case 0:
                return 0;
            default:
                printf("Not a valid option.\n");
                break;
        }
        enterToContinue();
    }
}