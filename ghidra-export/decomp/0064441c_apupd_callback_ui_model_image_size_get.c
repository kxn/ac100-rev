// func apupd_callback_ui_model_image_size_get @ 0064441c size=64

undefined4 apupd_callback_ui_model_image_size_get(int param_1,int *param_2)

{
  if ((*(int *)(param_1 + 0x7ec) == 2) &&
     ((*(int *)(param_1 + 0x140) == 1 || (*(int *)(param_1 + 0x140) == 4)))) {
    *param_2 = *param_2 + *(int *)(param_1 + 0x1ac);
  }
  return 0;
}

