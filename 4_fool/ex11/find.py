import requests

# Ask the user for the name of the Pokemon
pokemon_name = input("Enter the name of a Pokemon: ")

# Make a request to the PokeAPI to get information about the Pokemon
url = f"https://pokeapi.co/api/v2/pokemon/{pokemon_name}"
response = requests.get(url)

# If the request was successful, display the Pokemon's abilities
if response.status_code == 200:
    pokemon_info = response.json()
    print(f"Name: {pokemon_info['name'].capitalize()}")
    print("Abilities:")
    for ability in pokemon_info['abilities']:
        print(f"- {ability['ability']['name'].capitalize()}")
# If the request failed, display an error message
else:
    print(f"Error: Could not find Pokemon {pokemon_name.capitalize()}.")