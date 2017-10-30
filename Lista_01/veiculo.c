float distance(float vel, float tim){
    float total;
    total = vel/tim;
    return total;
}

float consume(float vel, float tim, float lit){
    float total;
    total = distance(vel,tim)/lit;
    return total;
}
