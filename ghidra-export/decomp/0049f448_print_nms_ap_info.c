// func print_nms_ap_info @ 0049f448 size=1

void print_nms_ap_info(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = apmngr_db_get_ap_max();
  if (param_1 < 0x20) {
    printf("print_nms_ap_info mask:%d \r\n",param_1);
    iVar2 = 0;
    printf("g_cloud_mngt_nms_ap_cnt=%d \r\n",*(undefined4 *)(&g_cloud_mngt_nms_ap_cnt + param_1 * 4)
          );
    while (iVar2 < iVar1) {
      if ((1 << (param_1 & 0x1f) & *(uint *)(g_cloud_mngt_ap_array + iVar2 * 8 + 4)) == 0) {
        iVar2 = iVar2 + 1;
      }
      else {
        printf("is nms ap:%d \r\n",iVar2);
        iVar2 = iVar2 + 1;
      }
    }
  }
  return;
}

