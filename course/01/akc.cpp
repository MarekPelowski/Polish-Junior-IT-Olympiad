#include <iostream>
#include <vector>

int findParticleSpeed(int particle, std::vector<int> particles)
{   
    int bottomRange = 0;
    int topRange = particles.size() - 1; // the last index

    // use binary search to find the index of the particle
    while(bottomRange < topRange) {
        int middle = (bottomRange + topRange) / 2;

        if(particles[middle] >= particle)
            topRange = middle;
        else
            bottomRange = middle + 1;
    }

    int particleCounter = 0;
    
    // count the particles by erasing them and adding to the counter
    while(particles[bottomRange] == particle && bottomRange < particles.size()){
        particleCounter++;
        particles.erase(particles.begin() + bottomRange);
    }

    return particleCounter;
}

int main()
{
    int n;
    std::cin >> n; // number of particles

    std::vector<int> particles(n); // particles speed
    for(int i = 0; i < n; i++){
        std::cin >> particles[i]; 
    }

    int q;
    std::cin >> q; // number of inquiries

    std::vector<int> results; // variable that contains the results
    for(int i = 0; i < q; i++){
        int particle;
        std::cin >> particle; // the particle speed to be found

        results.push_back(findParticleSpeed(particle, particles));
    }

    for(int i = 0; i < q; i++){
        std::cout << results[i] << std::endl;
    }

    return 0;
}