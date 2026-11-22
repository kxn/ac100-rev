// func rrm_ap_para_is_collect_finished @ 004b2ee0 size=100

bool rrm_ap_para_is_collect_finished(int *param_1)

{
  bool bVar1;
  
  if (param_1 == (int *)0x0) {
    bVar1 = true;
    if (rrm_err_switch != '\0') {
      printf("[RRM_ERROR]%s()/%d wrong input\n","rrm_ap_para_is_collect_finished",0x331);
    }
  }
  else {
    bVar1 = param_1[1] == *param_1;
  }
  return bVar1;
}

