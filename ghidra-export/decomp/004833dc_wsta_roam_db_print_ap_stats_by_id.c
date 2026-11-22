// func wsta_roam_db_print_ap_stats_by_id @ 004833dc size=228

void wsta_roam_db_print_ap_stats_by_id(uint param_1)

{
  char *pcVar1;
  
  FUN_004082d0(l_wsta_roam_data,0xffffffff);
  pcVar1 = (char *)(DAT_00767558 + (param_1 & 0xffff) * 0x28);
  if (*pcVar1 != '\0') {
    printf("ap id: %u\n",param_1 & 0xffff);
    printf("\t%s = %llu\n","trigger_pkt_rcv",*(undefined4 *)(pcVar1 + 8),
           *(undefined4 *)(pcVar1 + 0xc));
    printf("\t%s = %llu\n","trigger_sta_rcv",*(undefined4 *)(pcVar1 + 0x10),
           *(undefined4 *)(pcVar1 + 0x14));
    printf("\t%s = %llu\n","sta_nbr_selected",*(undefined4 *)(pcVar1 + 0x18),
           *(undefined4 *)(pcVar1 + 0x1c));
    printf("\t%s = %llu\n","result_pkt_send",*(undefined4 *)(pcVar1 + 0x20),
           *(undefined4 *)(pcVar1 + 0x24));
  }
  FUN_00407f30(l_wsta_roam_data);
  return;
}

