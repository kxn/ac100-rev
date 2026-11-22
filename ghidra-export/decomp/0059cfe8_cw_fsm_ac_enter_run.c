// func cw_fsm_ac_enter_run @ 0059cfe8 size=200

undefined4 cw_fsm_ac_enter_run(int param_1)

{
  undefined4 uVar1;
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [20];
  undefined2 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_fsm_ac_enter_run",0x143,"session");
    uVar1 = 0xffffffff;
  }
  else {
    memset(auStack_40,0,0x34);
    memcpy(auStack_30,(void *)(param_1 + 0x2c),0x14);
    local_1c = *(undefined2 *)(param_1 + 0x40);
    local_18 = *(undefined4 *)(param_1 + 0x44);
    local_14 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
    local_10 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
    if (*(int *)(param_1 + 0x10) != 0) {
      memcpy(auStack_40,(void *)(param_1 + 0x14),6);
    }
    serv_ent_handle(1,auStack_40,0,0);
    uVar1 = 0;
  }
  return uVar1;
}

