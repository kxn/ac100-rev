// func rdmngr_test_chnl_parse @ 00622718 size=240

void rdmngr_test_chnl_parse
               (int param_1,undefined4 param_2,int param_3,char param_4,undefined2 param_5,
               undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *__s;
  undefined4 local_60 [17];
  
  iVar1 = 1;
  if (param_1 != 0) {
    iVar1 = param_1;
  }
  if (param_3 == 0) {
    param_3 = 0x35001401;
  }
  __s = local_60;
  if (param_4 == '\0') {
    param_4 = '\x01';
  }
  memset(__s,0,0x40);
  iVar1 = rdmngr_db_get_mutex_chnl(param_3,param_2,param_4,param_5,iVar1,__s,param_6);
  printf("mutex_chnl cnt is %d.\n",iVar1);
  for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
    uVar2 = *__s;
    __s = __s + 1;
    printf("chnls[%d] is %d.\n",iVar3,uVar2);
  }
  return;
}

