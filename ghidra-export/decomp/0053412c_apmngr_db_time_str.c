// func apmngr_db_time_str @ 0053412c size=96

char * apmngr_db_time_str(uint param_1,char *param_2,size_t param_3)

{
  if (param_2 != (char *)0x0) {
    if ((int)param_3 < 1) {
      param_2 = (char *)0x0;
    }
    else {
      snprintf(param_2,param_3,"%02u:%02u:%02u",param_1 >> 0x18,param_1 >> 0x10 & 0xff,
               param_1 >> 8 & 0xff);
    }
  }
  return param_2;
}

