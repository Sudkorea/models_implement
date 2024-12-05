#include <vector>
#include <stdexcept>

using namespace std;

class LinearRegression {
private:
    float a, b, learning_rate;

    void GradientDescent(const vector<float>& x, const vector<float>& y, const vector<float>& yhat){

        if (y.size() != yhat.size())
            throw runtime_error("Vectors must be of the same length");

        float da = 0;
        float db = 0;

        for (int i = 0; i < y.size(); i++) {
            da += x[i] * (y[i] - yhat[i]);
            db += (y[i] - yhat[i]);
        }

        da *= -2 / y.size();
        db *= -2 / y.size();

        a -= learning_rate * da;
        b -= learning_rate * db;
    }

public:
    LinearRegression(float init_a = 0, float init_b = 0, float lr = 0.01) 
        : a(init_a), b(init_b), learning_rate(lr) {}

    vector<float> predict(const vector<float>& x) {
        vector<float> yhat(x.size());
        for (int i = 0; i < x.size(); i++) {
            yhat[i] = a * x[i] + b;
        }
        return yhat;
    }
    
    void train(const vector<float>& x, const vector<float>& y, int epochs) {
        for (int epoch = 0; epoch < epochs; epoch++) {
            vector<float> yhat = predict(x);
            GradientDescent(x, y, yhat);
        }
    }
};