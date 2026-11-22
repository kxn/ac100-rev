// func arp_defend_packet_bind_arps_get @ 00477144 size=172

undefined4 arp_defend_packet_bind_arps_get(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = (undefined4 *)(param_3 + param_1 * 0xc);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 0xffffffff;
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Invalid arp_entry id(%d)\n",
             "arp_defend_packet_bind_arps_get",0xca,param_1);
    }
  }
  else {
    uVar3 = 0xffffffff;
    if (*(char *)(param_2 + 4) == '\x01') {
      uVar3 = 0;
      *puVar2 = *(undefined4 *)(param_2 + 8);
      memcpy(puVar2 + 1,(void *)(param_2 + 0x18),6);
    }
  }
  return uVar3;
}

