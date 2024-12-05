#include <vector>
#include <stdexcept>
#include <fstream>

using namespace std;

float MSE(const vector<float>& y, const vector<float>& yhat) {
    if (y.size() != yhat.size())
        throw runtime_error("Vectors must be of the same length");

    float mse = 0;

    for (int i = 0; i < y.size(); i++) 
        mse += (y[i] - yhat[i]) * (y[i] - yhat[i]);
    
    mse /= y.size();

    return mse;
}

const vector<float> read_csv(string file_path) {
    
}