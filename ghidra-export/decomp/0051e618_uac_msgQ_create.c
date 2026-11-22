// func uac_msgQ_create @ 0051e618 size=336

mqd_t uac_msgQ_create(char *param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  mqd_t __mqdes;
  mq_attr local_38;
  
  __mqdes = -1;
  if (param_1 != (char *)0x0) {
    mq_unlink(param_1);
    memset(&local_38,0,0x20);
    local_38.mq_maxmsg = param_2;
    if (param_2 == 0) {
      local_38.mq_maxmsg = 0x1e;
    }
    local_38.mq_msgsize = param_3;
    if (param_3 == 0) {
      local_38.mq_msgsize = 0x80;
    }
    uVar1 = 2;
    if (((param_4 & 4) == 0) && (uVar1 = (param_4 << 0x1e) >> 0x1f, (param_4 & 1) != 0)) {
      uVar1 = 0;
    }
    __mqdes = mq_open(param_1,uVar1 | 0x100,0x1a4,&local_38);
    if (__mqdes == -1) {
      perror("");
    }
    else if ((param_4 & 8) != 0) {
      memset(&local_38,0,0x20);
      local_38.mq_flags = 0x80;
      mq_setattr(__mqdes,&local_38,(mq_attr *)0x0);
    }
  }
  return __mqdes;
}

