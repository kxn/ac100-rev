// func uac_com_get_dev_product_id @ 005162e0 size=1

undefined4 uac_com_get_dev_product_id(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_t9;
  undefined1 auStack_38 [44];
  
  uVar2 = 0xffffffff;
  if (param_1 != (undefined4 *)0x0) {
    iVar3 = *(int *)(in_t9 + 0x2430cc);
    iVar1 = *(int *)(in_t9 + 0x2430cc);
    if (*(int *)(iVar3 + 0x1e58) == 0) {
      if (**(int **)(in_t9 + 0x2430e8) != 0) {
        (**(code **)(in_t9 + 0x2435f0))
                  (*(int *)(in_t9 + 0x242e48) + 0xc40,*(int *)(in_t9 + 0x242e48) + 0x1e7c,0x201);
      }
      (**(code **)(in_t9 + 0x243510))(auStack_38,*(int *)(in_t9 + 0x242ecc) + 0x1e84,0x24);
      iVar1 = uac_com_uci_parse_req
                        (*(int *)(in_t9 + 0x242e48) + 0x1240,*(int *)(in_t9 + 0x242ec4) + 0x2dc4,
                         auStack_38,1);
      if (iVar1 != 0) {
        if (**(int **)(in_t9 + 0x2430ec) == 0) {
          return 0xffffffff;
        }
        (**(code **)(in_t9 + 0x2435f0))
                  (*(int *)(in_t9 + 0x242e48) + 0x124c,*(int *)(in_t9 + 0x242e48) + 0x1e7c,0x20a);
        return 0xffffffff;
      }
      *(undefined4 *)(iVar3 + 0x1e58) = 1;
      iVar1 = *(int *)(in_t9 + 0x2430cc);
    }
    uVar2 = 0;
    *param_1 = *(undefined4 *)(iVar1 + 0x1e5c);
  }
  return uVar2;
}

