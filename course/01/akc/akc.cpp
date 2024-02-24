#include <iostream>
#include <vector>

int findParticleSpeed(int particle, std::vector<int> &particles)
{   
    int bottomRange = 0;
    int topRange = particles.size() - 1; // the last index
    int bottomParticle, topParticle; 

    // use binary search to find the index of the first particle
    while(bottomRange < topRange) {
        int middle = (bottomRange + topRange) / 2;
        if(particles[middle] >= particle)
            topRange = middle;
        else
            bottomRange = middle + 1;
    }
    bottomParticle = bottomRange; // save the first particle index

    if(particles[bottomParticle] != particle)
        return 0;

    // use binary search again to find the index of the last particle
    topRange = particles.size() - 1;
    while(bottomRange < topRange) {
        int middle = (bottomRange + topRange + 1) / 2;
        if(particles[middle] <= particle)
            bottomRange = middle;
        else
            topRange = middle - 1;
    }
    topParticle = topRange;

    return (topParticle - bottomParticle) + 1;
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