{
  description = "Dynamic array using small buffer optimization (SBO)";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";

  outputs = { self, nixpkgs }: 
  let 
    system = "x86_64-linux";
    pkgs = nixpkgs.legacyPackages."${system}";
  in
  {
    packages."${system}".default = pkgs.stdenv.mkDerivation {
      name = "my-da";
      src = self;

      buildPhase = "make all";
      installPhase = ''
      install -D lib/libdynamic_array.so $out/lib/libdynamic_array.so;
      install -D lib/libdynamic_array.a $out/lib/libdynamic_array.a;
      '';
    };

    # Dev shell environment
    devShells."${system}".default = pkgs.mkShell {
      packages = with pkgs; [
        pkg-config
      ];
    };
  };
}
