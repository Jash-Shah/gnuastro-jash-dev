import cosmology

print(help(cosmology))

print("Age : ",                 cosmology.cosmology_age(z=5,H0 = 2))
print("Absolute Mag : ",        cosmology.cosmology_to_absolute_mag(5,5,0.2,0.3,0.5))
print("Proper Distance : ",     cosmology.cosmology_proper_distance(H0=5,olambda=0.2,oradiation=0.5,z=5,omatter=0.3))
print("Co-Moving Volume : ",    cosmology.cosmology_comoving_volume(H0=5,omatter=0.3,olambda=0.2,oradiation=0.5,z=5))
print("Critical Density : ",    cosmology.cosmology_critical_density(H0=5,olambda=0.2,oradiation=0.5,z=5,omatter=0.3))
print("Angular Distance : ",    cosmology.cosmology_angular_distance(H0=5,olambda=0.2,oradiation=0.5,z=5,omatter=0.3))
print("Luminosity Distance : ", cosmology.cosmology_luminosity_distance(5))
print("Distance Modulus : ",    cosmology.cosmology_distance_modulus(5,5,0.2,0.3,0.5))
print("Velocuty from Z : ",     cosmology.cosmology_velocity_from_z(5))
print("Z from Velocity : ",     cosmology.cosmology_z_from_velocity(2))