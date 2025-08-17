uint8_t map_volume_custom(uint8_t vol){
    /*if(vol <= 60)
        return (uint8_t)(100.0f * (0.8f * ((float)vol/60.0f)));
    else
        return (uint8_t)(100.0f * (0.8f + 0.2f * (vol - 60)/40.0f));
    */
    float x = (float)(vol / 100.0f);
    return (uint8_t) (100.0f * (1/(1.0f + expf(-10.0f*(x - 0.0f)))));
}