// func _rrm_freq_enable_set @ 004a9520 size=136

void _rrm_freq_enable_set(int param_1)

{
  if (param_1 == 0) {
    DAT_00731920 = 1;
    DAT_00731924 = 1;
    return;
  }
  if (param_1 == 1) {
    DAT_00731920 = param_1;
    DAT_00731924 = 0;
    return;
  }
  if (param_1 == 2) {
    DAT_00731920 = 0;
    DAT_00731924 = 1;
    return;
  }
  if (rrm_err_switch != '\0') {
    printf("[RRM_ERROR]%s()/%d freq_enable(%d) is err\n","_rrm_freq_enable_set",0x8ff,param_1);
    return;
  }
  return;
}

