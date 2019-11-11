uint8_t Bump_Read(void){
    uint8_t result;
    uint8_t first, second;

    first = ((P4->IN&0xE0)>>2);
    second = ((P4->IN&0x0D)>>1);

    result = (first) | (second) | (P4->IN&0x01);
    return (result);
}
