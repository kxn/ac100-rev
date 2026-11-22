// func uac_msgQ_getCurMsgNum @ 0051ead4 size=108

long uac_msgQ_getCurMsgNum(mqd_t param_1)

{
  int iVar1;
  long lVar2;
  mq_attr mStack_28;
  
  memset(&mStack_28,0,0x20);
  iVar1 = mq_getattr(param_1,&mStack_28);
  lVar2 = -1;
  if (iVar1 != -1) {
    lVar2 = mStack_28.mq_curmsgs;
  }
  return lVar2;
}

