// func cw_ac_check_recv_queue_threshold @ 00589364 size=352

void cw_ac_check_recv_queue_threshold(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  do {
    if (((ac != 0) && (iVar1 = FUN_004081b0(ac + 0xcc30), iVar1 != 0)) &&
       (iVar1 = 0, *(int *)(ac + 0x18) != 0)) {
      iVar5 = 0;
      uVar4 = 0;
      while (uVar2 = *(uint *)(ac + 0x18), uVar4 < uVar2) {
        iVar6 = uVar4 * 0xa0;
        iVar3 = cw_packet_queue_is_high_threshold
                          (*(undefined4 *)(*(int *)(ac + 0x1c) + iVar6 + 0x20));
        if (iVar3 == 0) {
          iVar5 = iVar5 + 1;
          uVar4 = uVar4 + 1;
        }
        else {
          uVar4 = uVar4 + 1;
          iVar3 = cw_packet_queue_is_low_threshold
                            (*(undefined4 *)(*(int *)(ac + 0x1c) + iVar6 + 0x20));
          iVar1 = iVar1 + (uint)(iVar3 == 0);
        }
      }
      if (iVar5 == 0) {
        if (uVar2 == 0) {
          trap(7);
        }
        if (0x31 < (uint)(iVar1 * 100) / uVar2) {
          for (iVar1 = FUN_004081b0(ac + 0xcc3c); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
            (**(code **)(iVar1 + 0xc))(0);
          }
        }
      }
      else {
        for (iVar1 = FUN_004081b0(ac + 0xcc30); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
          (**(code **)(iVar1 + 0xc))(0);
        }
      }
    }
    sleep(1);
  } while( true );
}

