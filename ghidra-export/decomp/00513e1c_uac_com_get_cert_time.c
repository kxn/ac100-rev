// func uac_com_get_cert_time @ 00513e1c size=1

undefined8 uac_com_get_cert_time(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int in_t9;
  undefined1 auStack_110 [256];
  
  (**(code **)(in_t9 + 0x24598c))(auStack_110,0,0x100);
  iVar1 = (**(code **)(in_t9 + 0x245968))
                    (*(int *)(in_t9 + 0x24530c) + 0xe2c,*(int *)(in_t9 + 0x2453a4) + 0x56c);
  if (iVar1 == 0) {
    if (**(int **)(in_t9 + 0x2455b0) != 0) {
      uVar4 = 0x364;
      iVar2 = *(int *)(in_t9 + 0x24530c);
      iVar1 = *(int *)(in_t9 + 0x24530c) + 0xcb0;
code_r0x00513fd0:
      iVar3 = 0;
      iVar5 = 0;
      (**(code **)(in_t9 + 0x245ab4))(iVar1,iVar2 + 0x1f20,uVar4);
      goto code_r0x00513f3c;
    }
  }
  else {
    (**(code **)(in_t9 + 0x24598c))(auStack_110,0,0x100);
    (**(code **)(in_t9 + 0x245a80))(auStack_110,1,0x100,iVar1);
    (**(code **)(in_t9 + 0x2459b4))(iVar1);
    if (**(int **)(in_t9 + 0x2455ac) != 0) {
      (**(code **)(in_t9 + 0x245ab4))
                (*(int *)(in_t9 + 0x24530c) + 0xce8,*(int *)(in_t9 + 0x24530c) + 0x1f20,0x36c,
                 auStack_110);
    }
    iVar1 = (**(code **)(in_t9 + 0x2459d0))(auStack_110);
    if (iVar1 == 0) {
      if (**(int **)(in_t9 + 0x2455b0) != 0) {
        uVar4 = 0x370;
        iVar2 = *(int *)(in_t9 + 0x24530c);
        iVar1 = *(int *)(in_t9 + 0x24530c) + 0xd2c;
        goto code_r0x00513fd0;
      }
    }
    else {
      iVar2 = (**(code **)(in_t9 + 0x245a74))(iVar1,*(int *)(in_t9 + 0x24530c) + 0xe58);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc) == 4)) {
        iVar3 = (**(code **)(in_t9 + 0x245a2c))(*(undefined4 *)(iVar2 + 0x10));
        iVar5 = iVar3 >> 0x1f;
        (**(code **)(in_t9 + 0x245a08))(iVar1);
        goto code_r0x00513f3c;
      }
      if (**(int **)(in_t9 + 0x2455b0) != 0) {
        (**(code **)(in_t9 + 0x245ab4))
                  (*(int *)(in_t9 + 0x24530c) + 0xd64,*(int *)(in_t9 + 0x24530c) + 0x1f20,0x37c);
      }
      (**(code **)(in_t9 + 0x245a08))(iVar1);
    }
  }
  iVar3 = 0;
  iVar5 = 0;
code_r0x00513f3c:
  return CONCAT44(iVar5,iVar3);
}

