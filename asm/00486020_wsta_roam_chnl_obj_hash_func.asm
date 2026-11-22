; func wsta_roam_chnl_obj_hash_func @ 0x00486020 size=0x30
  486020:	27bdffe0 	addiu	sp,sp,-32
  486024:	afb00018 	sw	s0,24(sp)
  486028:	afbf001c 	sw	ra,28(sp)
  48602c:	0c101ee4 	jal	0x407b90
  486030:	00808021 	move	s0,a0
  486034:	02002021 	move	a0,s0
  486038:	8fbf001c 	lw	ra,28(sp)
  48603c:	00003021 	move	a2,zero
  486040:	8fb00018 	lw	s0,24(sp)
  486044:	27bd0020 	addiu	sp,sp,32
  486048:	081020f4 	j	0x4083d0
  48604c:	00402821 	move	a1,v0
