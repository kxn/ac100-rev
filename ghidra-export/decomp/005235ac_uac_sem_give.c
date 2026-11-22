// func uac_sem_give @ 005235ac size=60

undefined4 uac_sem_give(sem_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sem_post(param_1);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}

