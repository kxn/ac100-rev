// func uac_msgQ_receive @ 0051e934 size=200

void uac_msgQ_receive(mqd_t param_1,char *param_2,size_t param_3,int param_4,uint *param_5)

{
  timespec local_20;
  
  local_20.tv_sec = 0;
  local_20.tv_nsec = 0;
  if ((param_2 != (char *)0x0) && (param_5 != (uint *)0x0)) {
    if (param_4 == -1) {
      mq_receive(param_1,param_2,param_3,param_5);
    }
    else {
      if (param_4 == 0) {
        local_20.tv_sec = 0;
        local_20.tv_nsec = 0;
      }
      else {
        uac_compute_timeout_ms(&local_20,param_4);
      }
      mq_timedreceive(param_1,param_2,param_3,param_5,&local_20);
    }
  }
  return;
}

