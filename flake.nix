rec {
  description = "A fractal/aliasing/moire-pattern thingy...";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-21.11";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in rec {
        packages = flake-utils.lib.flattenTree rec {

          rfrakt = pkgs.stdenv.mkDerivation {
            pname = "rfrakt";
            version = "0.0.0";
            src = nixpkgs.lib.cleanSource ./.;
            nativeBuildInputs = [
              pkgs.cmake
              pkgs.pkgconfig
              pkgs.qt5.wrapQtAppsHook
            ];
            buildInputs = [
              pkgs.qt5.qtbase
            ];
            meta = {
              mainProgram = "qrfrakt";
            };
           };
        };
        defaultPackage = packages.rfrakt;
      });
}
