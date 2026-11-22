// func apupd_entry_num_update @ 00648eb0 size=92

void apupd_entry_num_update(int param_1,int param_2)

{
  if (param_1 == 2) {
    if (param_2 != 0) {
      apupd_mult_manual_model_entry_num = apupd_mult_manual_model_entry_num + 1;
      return;
    }
    if (apupd_mult_manual_model_entry_num != 0) {
      apupd_mult_manual_model_entry_num = apupd_mult_manual_model_entry_num + -1;
    }
  }
  else {
    if (param_2 != 0) {
      apupd_mult_online_model_entry_num = apupd_mult_online_model_entry_num + 1;
      return;
    }
    if (apupd_mult_online_model_entry_num != 0) {
      apupd_mult_online_model_entry_num = apupd_mult_online_model_entry_num + -1;
      return;
    }
  }
  return;
}

