// func apupd_model_entry_basic_set @ 00649c48 size=160

undefined4 apupd_model_entry_basic_set(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0xa0);
  memcpy((void *)(param_1 + 0xa4),(void *)(param_2 + 0xa4),0x20);
  memcpy((void *)(param_1 + 0xc4),(void *)(param_2 + 0xc4),0x55);
  memcpy((void *)(param_1 + 0x5c),(void *)(param_2 + 0x5c),0x41);
  memcpy((void *)(param_1 + 0x119),(void *)(param_2 + 0x119),0x10);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_2 + 300);
  iVar1 = *(int *)(param_1 + 0x130);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_2 + 0x130);
  }
  *(int *)(param_1 + 0x130) = iVar1;
  *(undefined4 *)(param_1 + 0x134) = *(undefined4 *)(param_2 + 0x134);
  *(undefined1 *)(param_1 + 0x138) = *(undefined1 *)(param_2 + 0x138);
  return 0;
}

