// func arp_defend_packet_bind_nds_get @ 004771f0 size=200

undefined4 arp_defend_packet_bind_nds_get(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *__dest;
  undefined4 uVar2;
  
  __dest = (void *)(param_3 + param_1 * 0x16);
  if (__dest == (void *)0x0) {
    uVar2 = 0xffffffff;
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp_entry id(%d)\n","arp_defend_packet_bind_nds_get"
             ,0xdb,param_1);
    }
  }
  else {
    uVar2 = 0xffffffff;
    if (*(char *)(param_2 + 4) == '\x02') {
      memcpy(__dest,(void *)(param_2 + 8),0x10);
      uVar2 = 0;
      memcpy((void *)((int)__dest + 0x10),(void *)(param_2 + 0x18),6);
    }
  }
  return uVar2;
}

