int32_t LeftConvert(int32_t nl){        // returns left distance in mm
  // write this for Lab 4
    uint32_t length=0;
    length = 800000 / (nl-2000);
    if(nl>6000 & nl<=10000){
        length=-0.025*nl+350;
    }
    else if(nl>4000 & nl<=6000){
        length=-0.05*nl+500;
    }
    else if(nl>2500 & nl<=4000){
        length=(-0.0667)*nl+566;
    }
    else if(nl<=2500){
        length=(-0.2)*nl+900;
    }
    return length;
}
