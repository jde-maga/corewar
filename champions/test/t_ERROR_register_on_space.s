.name "kernel"
.comment "com" 

live %1
live %:label
label:
ld 9, r4

#TEST
ld %1,r 3
label:
sti	r4, %:label , r2
add	r2, r3, r2
