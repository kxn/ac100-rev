// func uac_arp_defend_uninit @ 00476cfc size=104

undefined4 uac_arp_defend_uninit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = arp_defend_db_uninit();
  if (((iVar1 != 0) && (uVar2 = 0xffffffff, arp_defend_err_switch != 0)) &&
     (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[ARP_DEFEND_ERROR]%s()/%d arp_defend_db_uninit() error.\n","uac_arp_defend_uninit",0x5e2
          );
  }
  return uVar2;
}

