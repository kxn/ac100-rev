// func uac_msgQ_send @ 0051e7b8 size=380

int uac_msgQ_send(mqd_t param_1,char *param_2,size_t param_3,uint param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  timespec local_30;
  
  local_30.tv_sec = 0;
  local_30.tv_nsec = 0;
  if ((param_2 != (char *)0x0) && (param_4 < 0x100)) {
    if (param_5 == -1) {
      do {
        iVar1 = mq_send(param_1,param_2,param_3,param_4);
        if (iVar1 != -1) {
          return iVar1;
        }
        piVar2 = __errno_location();
      } while ((*piVar2 == 0xb) || (*piVar2 == 4));
    }
    else {
      if (param_5 == 0) {
        local_30.tv_sec = 0;
        local_30.tv_nsec = 0;
      }
      else {
        uac_compute_timeout_ms(&local_30);
      }
      do {
        iVar1 = mq_timedsend(param_1,param_2,param_3,param_4,&local_30);
        if (iVar1 != -1) {
          return iVar1;
        }
        piVar2 = __errno_location();
      } while ((*piVar2 == 0xb) || (*piVar2 == 4));
    }
  }
  return -1;
}

