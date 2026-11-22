// func uac_com_get_dev_vendor_url @ 0051619c size=1

undefined4 uac_com_get_dev_vendor_url(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_t9;
  undefined1 auStack_38 [40];
  
  uVar2 = 0xffffffff;
  if ((param_1 != 0) && (1 < param_2)) {
    iVar3 = *(int *)(in_t9 + 0x243210);
    iVar1 = *(int *)(in_t9 + 0x243210);
    if (*(int *)(iVar3 + 0x1e60) == 0) {
      if (**(int **)(in_t9 + 0x24322c) != 0) {
        (**(code **)(in_t9 + 0x243734))
                  (*(int *)(in_t9 + 0x242f8c) + 0xc40,*(int *)(in_t9 + 0x242f8c) + 0x1e98,0x229);
      }
      (**(code **)(in_t9 + 0x243654))(auStack_38,*(int *)(in_t9 + 0x243010) + 0x1e60,0x24);
      iVar1 = uac_com_uci_parse_req
                        (*(int *)(in_t9 + 0x242f8c) + 0x1240,*(int *)(in_t9 + 0x243008) + 0x2dc4,
                         auStack_38,1);
      if (iVar1 != 0) {
        if (**(int **)(in_t9 + 0x243230) == 0) {
          return 0xffffffff;
        }
        (**(code **)(in_t9 + 0x243734))
                  (*(int *)(in_t9 + 0x242f8c) + 0x124c,*(int *)(in_t9 + 0x242f8c) + 0x1e98,0x232);
        return 0xffffffff;
      }
      *(undefined4 *)(iVar3 + 0x1e60) = 1;
      iVar1 = *(int *)(in_t9 + 0x243210);
    }
    uVar2 = 0;
    (**(code **)(in_t9 + 0x2434f0))(param_1,iVar1 + 0x1e64,param_2 + -1);
    *(undefined1 *)(param_1 + param_2 + -1) = 0;
  }
  return uVar2;
}

