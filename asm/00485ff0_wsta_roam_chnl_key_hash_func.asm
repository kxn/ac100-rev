; func wsta_roam_chnl_key_hash_func @ 0x00485ff0 size=0x30
  485ff0:	27bdffe0 	addiu	sp,sp,-32
  485ff4:	afb00018 	sw	s0,24(sp)
  485ff8:	afbf001c 	sw	ra,28(sp)
  485ffc:	0c101ee4 	jal	0x407b90
  486000:	00808021 	move	s0,a0
  486004:	02002021 	move	a0,s0
  486008:	8fbf001c 	lw	ra,28(sp)
  48600c:	00003021 	move	a2,zero
  486010:	8fb00018 	lw	s0,24(sp)
  486014:	27bd0020 	addiu	sp,sp,32
  486018:	081020f4 	j	0x4083d0
  48601c:	00402821 	move	a1,v0
