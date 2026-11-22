// func uac_wserv_packet_dump_by_id @ 005dabf8 size=1

void uac_wserv_packet_dump_by_id(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_300 [728];
  
  memset(auStack_300,0,0x2d8);
  if ((-1 < (int)param_1) && (iVar1 = apmngr_db_get_ap_max(), (int)param_1 < iVar1)) {
    FUN_004082d0(DAT_007598e4,0xffffffff);
    iVar1 = apmngr_db_entry_get_by_id(param_1 & 0xffff,auStack_300);
    if (iVar1 == 0) {
      puts("--------------------------");
      printf("AP[%d]:\n",param_1);
      iVar1 = param_1 * 0xc;
      uVar4 = 0;
      printf("\tis_waiting:%d\n",(uint)*(byte *)(DAT_007598e8 + iVar1 + 2));
      printf("\tmd5_packet_send:%d\n",(uint)*(byte *)(DAT_007598e8 + iVar1 + 3));
      printf("\tis_last_send:%d\n",(uint)*(byte *)(DAT_007598e8 + iVar1 + 4));
      printf("\tpkt_rd_cur:%d\n",*(char *)(DAT_007598e8 + iVar1) + 1);
      printf("\tpkt_wlan_cur:%d\n",*(char *)(DAT_007598e8 + iVar1 + 1) + 1);
      while( true ) {
        uVar2 = rdmngr_profile_get_max_rd_per_ap();
        if (uVar2 <= uVar4) break;
        iVar5 = 0;
        uVar2 = 0;
        while (uVar3 = rdmngr_profile_get_max_wlan_per_rd(), uVar2 < uVar3) {
          if (*(char *)(*(int *)(*(int *)(DAT_007598e8 + iVar1 + 8) + uVar4 * 4) + uVar2) == '\0') {
            uVar2 = uVar2 + 1;
          }
          else {
            if (iVar5 == 0) {
              printf("\t\t");
            }
            iVar5 = iVar5 + 1;
            printf("[%d-%d]:0x%02x ",uVar4 + 1,uVar2 + 1,
                   (uint)*(byte *)(*(int *)(*(int *)(DAT_007598e8 + iVar1 + 8) + uVar4 * 4) + uVar2)
                  );
            uVar2 = uVar2 + 1;
          }
        }
        if (iVar5 == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          putchar(10);
          uVar4 = uVar4 + 1;
        }
      }
      puts("--------------------------");
    }
    FUN_00407f30(DAT_007598e4);
  }
  return;
}

