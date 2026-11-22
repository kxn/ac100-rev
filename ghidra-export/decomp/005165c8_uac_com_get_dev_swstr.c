// func uac_com_get_dev_swstr @ 005165c8 size=1

undefined4 uac_com_get_dev_swstr(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_t9;
  undefined4 uStack_c8;
  int iStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined2 uStack_b0;
  undefined2 uStack_ae;
  undefined1 *puStack_ac;
  undefined4 uStack_a8;
  undefined1 auStack_a4 [136];
  
  uVar2 = 0xffffffff;
  (**(code **)(in_t9 + 0x2431e0))(auStack_a4,0,0x81);
  if ((param_1 != 0) && (iVar3 = *(int *)(in_t9 + 0x242de4), 1 < param_2)) {
    iVar1 = *(int *)(in_t9 + 0x242de4);
    if (*(int *)(iVar3 + 0x1dc4) == 0) {
      if (**(int **)(in_t9 + 0x242e00) != 0) {
        (**(code **)(in_t9 + 0x243308))
                  (*(int *)(in_t9 + 0x242b60) + 0xc40,*(int *)(in_t9 + 0x242b60) + 0x1e50,0x1a7);
      }
      iStack_c4 = *(int *)(in_t9 + 0x242e14) + 0x1068;
      uStack_c8 = 0;
      uStack_c0 = 1;
      uStack_bc = 1;
      uStack_b8 = 0;
      uStack_b4 = 0;
      uStack_b0 = 1;
      uStack_ae = 0x81;
      uStack_a8 = 0;
      puStack_ac = auStack_a4;
      iVar1 = uac_com_uci_parse_req
                        (*(int *)(in_t9 + 0x242b60) + 0x1240,*(int *)(in_t9 + 0x242bdc) + 0x2dc4,
                         &uStack_c8,1);
      if (iVar1 != 0) {
        if (**(int **)(in_t9 + 0x242e04) == 0) {
          return 0xffffffff;
        }
        (**(code **)(in_t9 + 0x243308))
                  (*(int *)(in_t9 + 0x242b60) + 0x124c,*(int *)(in_t9 + 0x242b60) + 0x1e50,0x1b0);
        return 0xffffffff;
      }
      iVar1 = *(int *)(in_t9 + 0x242de4);
      (**(code **)(in_t9 + 0x2430c4))(iVar1 + 0x1dc8,auStack_a4,0x80);
      *(undefined4 *)(iVar3 + 0x1dc4) = 1;
    }
    uVar2 = 0;
    (**(code **)(in_t9 + 0x2430c4))(param_1,iVar1 + 0x1dc8,param_2 + -1);
    *(undefined1 *)(param_1 + param_2 + -1) = 0;
  }
  return uVar2;
}

