#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, Q;
    vector <int> A, Lx, Rx, Kx;
    vector <int> ans;

    bool eachElementBetween(const vector<int> &X, int lo, int hi) {
        for (int x : X) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }

    void InputFormat() {
        LINE(N, Q);
        LINE(A % SIZE(N));
        LINES(Lx, Rx, Kx) % SIZE(Q);
    }

    void OutputFormat() {
        LINE(ans) % SIZE(Q);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(64);
    }

    void Constraints()
        {
            CONS(1 <= N && N <= 1000000);
            CONS(1 <= Q && Q <= 100000);
            CONS(eachElementBetween(A, 1, 1000000000));
            CONS(eachElementBetween(Lx, 1, N));
            CONS(eachElementBetween(Rx, 1, N));
            CONS(eachElementBetween(Lx, 1, 1000000000));
        }

    void Subtask1()
        {
            Points(20);
            CONS(1 <= N && N <= 1000);
            CONS(1 <= Q && Q <= 1000);
        }

    void Subtask2()
        {
            Points(80);
        }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:

    void SampleTestCase1() {

        Input({
            "5 5",
            "2 3 2 4 5",
            "1 2 1000",
            "1 4 10000",
            "1 5 100000",
            "1 5 1000",
            "1 5 15"
        });

        Output({
            "166",
            "208",
            "416",
            "4",
            "0"
        });
    }

    void BeforeTestCase() {
        A.clear();
        Lx.clear();
        Rx.clear();
        Kx.clear();
    }

    void TestCases() {
        CASE(N = 1000, Q = 1000, randomA(N, A), randomQ(N, Q, Lx, Rx), randomK(Q, Kx));
        CASE(N = 1000, Q = 1000, randomA(N, A), randomQ(N, Q, Lx, Rx), randomK(Q, Kx));
        CASE(N = 1000, Q = 1000, randomA(N, A), randomQ(N, Q, Lx, Rx), randomK(Q, Kx));
        CASE(N = 1000000, Q = 100000, randomA(N, A), randomQ(N, Q, Lx, Rx), randomK(Q, Kx));
        CASE(N = 1000000, Q = 100000, randomA(N, A), randomQ(N, Q, Lx, Rx), randomK(Q, Kx));
        CASE(N = 1000000, Q = 100000, randomA(N, A), randomQ(N, Q, Lx, Rx), randomK(Q, Kx));
    }

private:

    void randomA(int N, vector <int> A) 
        {
            for (int i = 0; i < N; i++) {
                A.push_back(rnd.nextInt(1000000));
            }
        }

    void randomQ(int N, int Q, vector <int> Lx, vector <int> Rx)
        {
            for(int i = 0; i < Q; i++) {
                int l = rnd.nextInt(N - 1) + 1;
                int r = l + rnd.nextInt(N - l) + 1;
                Lx.push_back(l), Rx.push_back(r);
            }
        }

    void randomK(int Q, vector <int> Kx) 
        {
            for (int i = 0; i < Q; i++) {
                Kx.push_back(rnd.nextLongLong(10000000000) + 1);
            }
        }
};