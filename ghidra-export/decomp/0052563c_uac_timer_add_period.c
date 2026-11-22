// func uac_timer_add_period @ 0052563c size=1

undefined4
uac_timer_add_period
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  int in_t9;
  
  iVar4 = *(int *)(in_t9 + 0x233e2c);
  uac_mutex_take(*(undefined4 *)(iVar4 + 0x3bd4),0xffffffff);
  puVar3 = *(undefined1 **)(in_t9 + 0x233ea0);
  *puVar3 = 2;
  uVar1 = _uac_timer_add(param_1,param_2,param_3,param_4,param_5,*(int *)(in_t9 + 0x233aec) + 0x4388
                         ,0x205);
  uVar2 = *(undefined4 *)(iVar4 + 0x3bd4);
  *puVar3 = 0;
  uac_mutex_give(uVar2);
  return uVar1;
}

