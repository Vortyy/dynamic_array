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
      name = "my_da";
      src = self;

      buildPhase = "make all";
      installPhase = ''
      install -D $src/lib/* $out/lib/
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
